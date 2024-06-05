package main

import (
	"sync"
	"go/philosopher"
	"go/fork"
)

const numberOfPhilosophers = 3
const mealLimit = 3

var waitGroup = sync.WaitGroup{}

func main() {
	var forks [numberOfPhilosophers]fork.Fork
	var philosophers [numberOfPhilosophers]*philosopher.Philosopher

	for i := 0; i < numberOfPhilosophers; i++ {
		lowerForkIndex := i
		higherForkIndex := (i + 1) % numberOfPhilosophers

		if lowerForkIndex > higherForkIndex {
			lowerForkIndex, higherForkIndex = higherForkIndex, lowerForkIndex
		}

		philosophers[i] = &philosopher.Philosopher{
			Id:			i + 1,
			LowerFork:	&forks[lowerForkIndex],
			HigherFork: &forks[higherForkIndex],
			MealsCount: mealLimit,
			WaitGroup:			&waitGroup,
		}
	}

	for _, philosopher := range philosophers {
		waitGroup.Add(1)
		go philosopher.Dine()
	}

	waitGroup.Wait()
}
