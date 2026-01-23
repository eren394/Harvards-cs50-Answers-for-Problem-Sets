from cs50 import get_float

def main():
    # Prompt user for change owed (must be non-negative)
    while True:
        dollars = get_float("Change owed: ")
        if dollars >= 0:
            break

    # Convert dollars to cents to avoid floating-point errors
    # We round to the nearest penny and convert to an integer
    cents = int(round(dollars * 100))

    coins = 0

    # Calculate Quarters (25¢)
    coins += cents // 25
    cents %= 25

    # Calculate Dimes (10¢)
    coins += cents // 10
    cents %= 10

    # Calculate Nickels (5¢)
    coins += cents // 5
    cents %= 5

    # Calculate Pennies (1¢)
    coins += cents

    # Print the total number of coins
    print(coins)

if __name__ == "__main__":
    main()
