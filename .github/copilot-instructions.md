## Purpose
Short, actionable guidance for AI coding agents working on this repository (small C++ competitive-programming snippets). Focus on what to change, build, and test locally.

## Repo layout (important files)
- `bisection_integer.cpp`, `bisection(2).cpp` — primary C++ source files. Single-file programs using global variables and `solve()`/`solve2()` entry points.
- `.vscode/settings.json` — file associations mapping many standard headers to C++ (useful when editing).

## High-level architecture / why things are structured this way
- These are small, single-file solutions intended for local compile-and-run or online judges. No build system, frameworks, or libraries beyond STL.
- Code uses global state (e.g., `ll a, b, c, k;`) and macro-based shortcuts to speed up writing competitive solutions.

## Project-specific conventions and patterns
- Macros: many single-letter or short macros are used (e.g., `#define ll long long`, `#define f(i,s,e) for(...)`). Preserve naming when editing nearby code to remain consistent.
- I/O pattern: `main()` reads a test-case count `t` and calls `solve()` / `solve2()` repeatedly. Keep that structure when adding problems.
- Functions often rely on globals (e.g., `calc`, `seriesSum`). Be cautious when refactoring to pass parameters instead of keeping globals.
- Debug prints: authors use `cout << mid << ...` inside loops for step tracing. Expect to remove or gate these when finalizing code.

## Build & run (local developer workflows)
- There is no project/Makefile. Two common ways to compile a file in this workspace:
  - g++ (MinGW/Cygwin/WSL): `g++ -std=gnu++17 -O2 bisection_integer.cpp -o bisection_integer.exe`
  - MSVC (cl): `cl /EHsc /O2 bisection_integer.cpp` on Developer Command Prompt
- VS Code task (provided if you use the workspace): a `build` task exists that runs `msbuild` — but it may not apply because there is no .sln/.vcxproj in repo. Prefer direct compiler invocation unless a project file is added.

## Debugging tips and common pitfalls observed in this codebase
- Ensure `using namespace std;` appears before unqualified `string` usage (some files declared `string` before bringing in `std`).
- Binary-search loops in these files sometimes update both `l` and `r` incorrectly (causes infinite loops). When inspecting `solve2()` or similar, check that each iteration reduces the search interval.
- Watch for integer overflow in expressions like `a * x * x` if `a` and `x` are large — keep types as `long long` and consider safe checks.

## What to change and how to validate changes
- When editing a single-file solution: compile with `g++` locally and run with sample input. Keep all I/O on `stdin`/`stdout`.
- If adding files, mimic the existing lightweight style (single-file, `solve()` called from `main()`), and add short comments explaining new globals.

## Examples from repo
- `bisection_integer.cpp` uses `ll calc(ll x)` and global `a,b,c,k`. `main()` reads `t` then calls `solve()`.
- `bisection(2).cpp` (and `bisection_integer.cpp`) include debug `cout << mid <<` prints inside binary-search loops — useful for step debugging but noisy for final runs.

## Limits of what can be discovered automatically
- No unit tests, CI, or README present — agent should ask the maintainer about desired test cases, preferred compiler, or CI before making large changes.

If anything here is unclear or you want this tailored toward a different workflow (for example adding unit tests, or converting to a build system), tell me what to focus on and I'll iterate.
