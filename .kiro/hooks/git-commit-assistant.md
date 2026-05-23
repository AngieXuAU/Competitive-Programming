---
trigger: preTaskExecution
action: askAgent
---
If the previous 'git status' command returned any untracked or modified files, halt execution and address the user:
1. Alert them that they have uncommitted work from their previous problem.
2. Ask them which problem they just solved (e.g., "CF-123A" or "LeetCode 42") and a 1-sentence note on the core algorithm used.
3. Run a git commit command for them using the format: `solv(<platform>): <problem_id> - <core_algorithm_or_note>`
4. If the workspace is already clean, allow them to proceed smoothly to the next problem.