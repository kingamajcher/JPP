import threading
import time
import random

class Philosopher(threading.Thread):
    def __init__(self, id, lower_fork, higher_fork, meals_count):
        threading.Thread.__init__(self)
        self.id = id
        self.lower_fork = lower_fork
        self.higher_fork = higher_fork
        self.meals_count = meals_count

    def run(self):
        for _ in range(self.meals_count):
            self.think()
            self.eat()

    def think(self):
        print(f"Philosopher {self.id} is thinking.")
        time.sleep(random.uniform(1, 3))

    def eat(self):
        # Podnoszenie widelców
        forks_acquired = False
        while not forks_acquired:
            if self.lower_fork.has_token():
                self.lower_fork.acquire()
                self.lower_fork.take_token()  # Zabiera token lewego widelca
                if self.higher_fork.has_token():
                    self.higher_fork.acquire()
                    self.higher_fork.take_token()  # Zabiera token prawego widelca
                    forks_acquired = True
                else:
                    self.lower_fork.release()
                    self.lower_fork.give_token()
            time.sleep(random.uniform(0.1, 0.5))

        # Filozof zdobył oba widelce
        print(f"Philosopher {self.id} is eating.")
        time.sleep(random.uniform(1, 2))

        # Zwolnienie widelców i oddanie tokenów
        self.higher_fork.release()
        self.higher_fork.give_token()

        self.lower_fork.release()
        self.lower_fork.give_token()

        print(f"Philosopher {self.id} finished eating.")
