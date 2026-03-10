import unittest
from src.validator import validate_attendee

class TestValidator(unittest.TestCase):

    def test_valid_attendee(self):
        attendee = {
            "name": "Sara Palacios",
            "email": "sara@example.com",
            "age": 25,
            "ticket_type": "vip",
        }
        self.assertEqual(validate_attendee(attendee), [])

    def test_invalid_email(self):
        attendee = {
            "name": "Juan",
            "email": "juanexample.com",
            "age": 20,
            "ticket_type": "general",
        }
        self.assertIn("Invalid email", validate_attendee(attendee))

    def test_underage_attendee(self):
        attendee = {
            "name": "Ana",
            "email": "ana@example.com",
            "age": 16,
            "ticket_type": "student"
        }
        self.assertIn("Attendee must be 18 or older", validate_attendee(attendee))

    def test_invalid_registration_code(self):
        attendee = {
            "name": "karen",
            "email": "Karen@example.com",
            "age": 21,
            "ticket_type": "student",
            "registration_code": "EV-12"
        }
        self.assertIn("Invalid registration code", validate_attendee(attendee))

    def test_valid_registration_code(self):
        attendee = {
            "name": "andrea",
            "email": "andrea@example.com",
            "age": 21,
            "ticket_type": "student",
            "registration_code": "EV-1234"
        }
        self.assertEqual(validate_attendee(attendee), [])

if __name__ == "__main__":
    unittest.main()