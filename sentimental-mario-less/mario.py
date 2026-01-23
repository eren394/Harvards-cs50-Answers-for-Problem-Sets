from cs50 import get_int

def main():
    # Prompt user for height and validate (1-8)
    while True:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            break

    # Build the pyramid
    for i in range(1, height + 1):
        # Calculate spaces and hashes
        spaces = height - i
        hashes = i

        # In Python, you can multiply strings to repeat them!
        print(" " * spaces + "#" * hashes)

if __name__ == "__main__":
    main()
