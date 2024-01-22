import os
import timeit
import subprocess

def main():
    # Ask for a filename
    filename = input("Enter the name of the python file to test (without .py): ")

    # Define directory
    directory = "secret"

    # List all the .in files
    input_files = sorted([f for f in os.listdir(directory) if f.endswith('.in')])

    # Initialize counters
    total_cases = 0
    correct_cases = 0

    # Run the python file on each .in file and compare output to .ans file
    for in_file in input_files:
        ans_file = os.path.join(directory, in_file.replace('.in', '.ans'))
        in_file = os.path.join(directory, in_file)

        # Ensure corresponding .ans file exists
        if not os.path.exists(ans_file):
            print(f"No answer file found for {in_file}. Skipping.")
            continue

        total_cases += 1

        # Run the python file and time it
        start_time = timeit.default_timer()

        try:
            output = subprocess.check_output(f"python {filename}.py < {in_file}", shell=True, timeout=10).decode()
        except subprocess.TimeoutExpired:
            print(f"Time limit exceeded for test case: {in_file}.")
            break
        except Exception as e:
            print(f"Error occurred while running test case {in_file}: {str(e)}")
            continue

        elapsed = timeit.default_timer() - start_time

        # Open the answer file and compare
        with open(ans_file, 'r') as f:
            ans = f.read()

        if ''.join(output).replace('\n','') == ''.join(ans).replace('\n',''):
            print(f"Test case {in_file} passed in {elapsed} seconds.")
            correct_cases += 1
        else:
            print(f"Test case {in_file} failed.")
            ans_lines = ans.count('\n')+1
            if ans_lines <= 2:
                print(f"Expected output:\n{ans}\nBut got:\n{output}")

    print(f"Out of {total_cases} test cases, {correct_cases} passed.")

if __name__ == "__main__":
    main()
