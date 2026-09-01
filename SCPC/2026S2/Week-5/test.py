import subprocess
import sys

# Paths to files and executable

program = input("Enter the name of the program (no extensions): ")

EXEC_PATH = f"./{program}.exe" # or "python3 solution.py"
INPUT_FILE = f"{program}/in.txt"
EXPECTED_FILE = f"{program}/expected.txt"

def run_test():
    # Read input file
    with open(INPUT_FILE, "r") as f:
        input_data = f.read()

    # Read expected output file
    with open(EXPECTED_FILE, "r") as f:
        expected_output = f.read().strip().splitlines()

    # Run executable with input redirected
    result = subprocess.run([EXEC_PATH], input=input_data, text=True, capture_output=True)

    if result.returncode != 0:
        print(f"❌ RUNTIME ERROR:\n{result.stderr}")
        return

    actual_output = result.stdout.strip().splitlines()

    # Compare output line by line
    passed = True
    for i, (actual, expected) in enumerate(zip(actual_output, expected_output), 1):
        actual_str = actual.strip()
        expected_str = expected.strip()
        
        if actual_str == expected_str:
            print(f"Test case {i}: ✅ PASS (Got: {actual_str})")
        else:
            print(f"Test case {i}: ❌ FAIL | Expected: '{expected_str}' | Got: '{actual_str}'")
            passed = False

    if passed and len(actual_output) == len(expected_output):
        print("\n🎉 ALL TEST CASES PASSED!")
    else:
        print("\n⚠️ SOME TEST CASES FAILED OR OUTPUT LENGTH MISMATCHED!")

if __name__ == "__main__":
    run_test()
