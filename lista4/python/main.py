from fork import Fork
from philosopher import Philosopher

def main(num_philosophers, meals_count):
    # Tworzenie widelców
    forks = [Fork(i) for i in range(1, num_philosophers + 1)]
    philosophers = []

    # Tworzenie filozofów
    for i in range(1, num_philosophers + 1):
        lower_fork = forks[i - 1]
        higher_fork = forks[(i % num_philosophers)] if i % num_philosophers != 0 else forks[0]
        
        # Ustalanie niższego i wyższego widelca
        if lower_fork.id > higher_fork.id:
            lower_fork, higher_fork = higher_fork, lower_fork
        
        philosopher = Philosopher(i, lower_fork, higher_fork, meals_count)
        philosophers.append(philosopher)

    # Startowanie wątków filozofów
    for philosopher in philosophers:
        philosopher.start()

    # Oczekiwanie na zakończenie wątków
    for philosopher in philosophers:
        philosopher.join()


if __name__ == "__main__":
    num_philosophers = 7
    meals_count = 3
    main(num_philosophers, meals_count)
