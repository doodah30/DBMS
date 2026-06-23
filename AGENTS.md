# RMDB Competition Development Guide

## Project Structure

- `src/rmdb.cpp`: server entry, database open/create, recovery, TCP handling, SQL dispatch.
- `rmdb_client/main.cpp`: interactive client over TCP/Unix socket.
- `src/parser/`: SQL lexer/parser. Edit `lex.l`, `yacc.y`, and AST definitions here.
- `src/analyze/`: semantic checks for tables, columns, types, predicates, groups, joins, and aggregates.
- `src/optimizer/`: logical plans and optimizations such as index selection, pushdown, join order, sort, and `explain`.
- `src/execution/`: executors for insert, delete, update, scan, index scan, join, projection, and sort.
- `src/system/`: metadata and DDL, including table/index create/drop, `show tables`, `desc`, and meta persistence.
- `src/storage/`: disk manager, page abstraction, and buffer pool.
- `src/replacer/`: replacement policy, mainly LRU.
- `src/record/`: record files, record pages, and record scans.
- `src/index/`: B+ tree index and index scans.
- `src/transaction/`: transactions, locks, timestamps, MVCC, write sets, and rollback.
- `src/recovery/`: logging, redo/undo, crash recovery, and checkpoints.
- `src/unit_test.cpp`: GoogleTest unit tests for low-level modules.
- `tests/`: local tests derived from `docs/测试说明文档.md`, including SQL cases, expected output, and Python/C++ runners.
- `docs/`: project, environment, competition, and test documentation.
- `deps/`: third-party dependencies. Do not modify them.

## Restrictions

- Do not copy or borrow code from previous teams, online sources, external DBMS projects, or incompatible licenses unless explicitly requested.
- Do not change the root CMakeLists.txt, adjust project layout or modify the `deps/` directory unless explicitly required;  additionally, do not commit build folders (including `build/`, `rmdb_client/build/`, `database`), logs or generated binaries.
- Do not hand-edit generated parser files first. Prefer editing `lex.l` and `yacc.y`, then regenerate.
- Do not hard-code output to pass tests; implement genuine kernel behavior, refrain from altering expected test output unless the official specification is updated, and never silently skip failing tests—document all temporary skips clearly.

## Development Principles

- Implement small, fine-grained features one at a time and commit promptly in small increments as a strict development rule.
- Fix root causes rather than symptoms, ensure correctness prior to performance tuning, and optimize with explainable strategies.
- Keep module boundaries clear: parser builds AST, analyzer validates, optimizer plans, executors run, storage persists.
- Maintain all invariants after every write: records, indexes, metadata, locks, logs, and transaction state.

## Git Workflow

### Commit Discipline

- Always start with git status --short and confirm it only lists intended files.
- Commit discipline is mandatory: make small commits, each focused on one fine-grained logical change. Commit verified changes promptly, and do not accumulate large batches of work.
- Hard guardrail: do not let a single logical batch grow beyond roughly `3-5` tracked files or cross multiple subsystems without making an intermediate commit first.
- Hard guardrail: once a small checkpoint has been verified (for example one target builds, one failing case turns green, or one parser/system/executor slice is finished), stop and commit before continuing to the next slice.
- If you notice that many files have already accumulated without a commit, treat that as a workflow error: pause feature work immediately, split the batch, and commit the smallest verified subset before editing anything else.
- Stage only related files and use short English commit messages under 20 words.

### Pre-Commit Checks

- Relevant builds should pass before committing.
- Relevant tests should be run, and any failures must be understood.
- New SQL features should have static or generated local tests.
- No logs, database folders, binaries, temporary files, or unrelated changes should be staged.

## Build

```bash
cmake --build build --target rmdb
cmake --build build --target unit_test
cmake --build build --target test_parser
```

If parser grammar changes:

```bash
cd src/parser
flex --header-file=lex.yy.hpp -o lex.yy.cpp lex.l
bison --defines=yacc.tab.hpp -o yacc.tab.cpp yacc.y
```

## Testing

Run checks from narrow to broad: build the touched target, run the nearest unit test, run one doc test, then the full problem group. Before sharing, run all local tests.

### Unit Tests

```bash
ctest --test-dir build --output-on-failure
./build/bin/unit_test
```

If `unit_test` fails in an unfinished low-level module, fix that module before relying on SQL tests.

### Document Tests

Python runner covers static SQL, generated index performance tests, transaction tests, MVCC schedules, and crash recovery:

```bash
python3 tests/run_doc_tests.py --list
python3 tests/run_doc_tests.py 02_01 --show-server-log
python3 tests/run_doc_tests.py 03_04 --row-count 3000 --index-ratio 0.70
python3 tests/run_doc_tests.py 08_02 --show-server-log
python3 tests/run_doc_tests.py 09_06 --recovery-row-count 1000 --recovery-ratio 0.70 --keep-db --show-server-log
```

C++ runner is faster and closer to `rmdb_client`, but only covers static SQL/expected cases:

```bash
g++ -std=c++17 -O2 tests/rmdb_doc_test.cpp -o tests/rmdb_doc_test
tests/rmdb_doc_test --list
tests/rmdb_doc_test 02_01
```

With older GCC, link filesystem explicitly:

```bash
g++ -std=c++17 -O2 tests/rmdb_doc_test.cpp -o tests/rmdb_doc_test -lstdc++fs
```
