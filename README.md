### Mini Shell — Capstone
**Project:** A working Unix shell built from scratch.
 
Features:
- Runs any system command with arguments (`ls -la`, `gcc file.c -o out`, `./program`)
- `fork`/`execvp`/`waitpid` cycle for every external command
- Built-in `cd` — uses `chdir()` directly in shell process (can't fork — would affect child only)
- Built-in `exit` — breaks loop, calls cleanup
- Built-in `history` — shows all previous commands
- Command history powered by the doubly linked list from concept 4
- Input parsing with `strtok`
- Multi-file structure with `Makefile`
**Key lessons:** `fork`/`exec` model, why built-ins can't be forked, `execvp` null-terminated args array, `waitpid`, reusing previously built data structures in a real project.
 
---
 
## Tools Used
 
| Tool | Purpose |
|------|---------|
| `gcc` | Compilation |
| `valgrind --leak-check=full` | Memory leak and error detection |
| `make` | Incremental build system |
| WSL (Ubuntu) | Linux environment on Windows |
| VS Code | Editor |
 
---
