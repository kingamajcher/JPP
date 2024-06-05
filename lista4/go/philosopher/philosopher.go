package philosopher

import (
	"fmt"
	"math/rand"
	"time"
	"go/fork"
	"sync"
)

type Philosopher struct {
	Id			int
	LowerFork	*fork.Fork
	HigherFork	*fork.Fork
	MealsCount	int
	WaitGroup	*sync.WaitGroup
}

func (p *Philosopher) Think() {
	fmt.Printf("Philosopher %d is thinking. \n", p.Id)
	time.Sleep(time.Duration(rand.Float64() * 2 * float64(time.Second)))
	fmt.Printf("Philosopher %d stopped thinking.\n", p.Id)
}

func (p *Philosopher) Eat() {
	p.LowerFork.PickUp()
	p.HigherFork.PickUp()

	fmt.Printf("Philosopher %d is eating.\n", p.Id)
	time.Sleep(time.Duration(rand.Float64() * float64(time.Second)))
	fmt.Printf("Philosopher %d stopped eating.\n", p.Id)

	p.HigherFork.PutDown()
	p.LowerFork.PutDown()
}

func (p *Philosopher) Dine() {
	for i := 0; i < p.MealsCount; i++ {
		p.Think()
		p.Eat()
	}
	defer p.WaitGroup.Done()
}
