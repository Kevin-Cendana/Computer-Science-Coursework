def create_large_test_file(filename, size_mb):
    # Size of each line (roughly 50 characters)
    line_size = 50
    # Number of lines to reach the desired file size
    num_lines = (size_mb * 1024 * 1024) // line_size

    with open(filename, "w") as file:
        for _ in range(num_lines):
            # Create a line with a repetitive pattern
            line = "abcde" * 10  # Adjust the pattern as needed
            file.write(line + "\n")

# Replace 'testfile.txt' with your desired file name and 300 with the size in MB
create_large_test_file("py_testfile.txt", 300)
