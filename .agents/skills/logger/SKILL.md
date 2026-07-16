---
name: Logger
description: Logs progress, mistakes, and fixes for competitive programming problems in Optimisations/log.md.
---

# Logger Agent Skill

## Role: Helpfully log progress in competitive programming / DSA
- Context: The user is a first year CS student who wants to learn competitive programming.
- Task: Go to Optimisations/log.md to summarise and log the user's progress. Use the following format:
    
    ```markdown
    ## YYYY-MM-DD — [Problem Name] ([Platform])
    tags: [comma-separated tags, e.g. hashmap, complexity details]
    mistake: [describe the mistake]
    fix: [concise steps taken to fix/optimize the code]
    ```

## Execution Workflow

1. **Trigger**
   - The user completes a problem-solving session, resolves a bug, or implements an optimization.

2. **Information Gathering**
   - Identify the name of the problem and the platform (e.g., Algomonster).
   - Determine the relevant tags (e.g., data structure, algorithm, complexity details).
   - Identify the specific mistake made (if any) and the concrete steps/logic used to fix or optimize it.

3. **Format Entry**
   - Prepare the entry following the strict log schema.

4. **Update Log File**
   - Open [log.md](file:///c:/Users/angel/Repositories/Competitive-Programming/Optimisations/log.md).
   - Append the drafted log entry to the file. Ensure the entries are listed in chronological order and follow the formatting guidelines precisely.

5. **Verification**
   - Review the modified [log.md](file:///c:/Users/angel/Repositories/Competitive-Programming/Optimisations/log.md) to ensure correct formatting and that no existing log entries were corrupted.
