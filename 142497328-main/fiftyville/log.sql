-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

SELECT name, transcript FROM interviews
WHERE month = 7 AND day = 28;

-- 1. Hırsızı Bulalım
SELECT name FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE bakery_security_logs.year = 2025 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute BETWEEN 15 AND 25
AND atm_transactions.year = 2025 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw'
AND phone_calls.year = 2025 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration < 60;

SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights
WHERE year = 2025 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1);

SELECT name FROM people
WHERE phone_number = (SELECT receiver FROM phone_calls
WHERE caller = (SELECT phone_number FROM people WHERE name = 'Bruce')
AND year = 2025 AND month = 7 AND day = 28 AND duration < 60);
