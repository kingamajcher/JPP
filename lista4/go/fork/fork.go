package fork

import (
	"sync"
)

type Fork struct {
	sync.Mutex
}

func (f *Fork) PickUp() {
	f.Lock()
}

func (f *Fork) PutDown() {
	f.Unlock()
}