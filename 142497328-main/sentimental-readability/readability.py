from cs50 import get_string

def main():
    # Get input text from the user
    text = get_string("Text: ")

    letters = 0
    words = 1  # Start at 1 because the last word isn't followed by a space
    sentences = 0

    # Iterate through the string to count letters, words, and sentences
    for char in text:
        if char.isalpha():
            letters += 1
        elif char.isspace():
            words += 1
        elif char in [".", "!", "?"]:
            sentences += 1

    # Coleman-Liau index calculation
    # L is the average number of letters per 100 words
    # S is the average number of sentences per 100 words
    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)

    # Output the result
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()
