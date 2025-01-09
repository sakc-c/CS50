import csv
import sys


def main():

    content = ""

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("command line arguments missing")
    else:
        csvFile = sys.argv[1]
        textFile = sys.argv[2]

    # TODO: Read database file into a variable
    database = {}

    with open(csvFile, "r") as file:
        reader = csv.DictReader(file)  # Automatically uses the first row as column headers
        for row in reader:
            name = row['name']
            # row.items() gives you key-value pairs for that row.
            database[name] = {key: int(value) for key, value in row.items() if key != 'name'}

    # TODO: Read DNA sequence file into a variable
    with open(textFile, "r") as text:
        content = text.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_counts = {}
    first_person = next(iter(database))
    for str_sequence in database[first_person]:  # next(iter(people_data)) means first person
        str_counts[str_sequence] = longest_match(content, str_sequence)

    # TODO: Check database for matching profiles
    for name, str_data in database.items():
        if all(str_counts[str_sequence] == str_data[str_sequence] for str_sequence in str_data):
            print(name)
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
