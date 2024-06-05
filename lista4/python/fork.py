import threading

class Fork:
    def __init__(self, id):
        self.id = id
        self.lock = threading.Lock()
        self.token = True  # Token wskazujący, czy widelec jest dostępny

    def acquire(self):
        self.lock.acquire()

    def release(self):
        self.lock.release()

    def has_token(self):  # Sprawdza czy ma token
        return self.token

    def take_token(self):  # Zabiera token - widelec jest zajęty
        self.token = False

    def give_token(self):  # Oddaje token - widelec jest dostępny
        self.token = True