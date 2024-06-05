with Fork;

package Philosopher is
    task type Philosopher_Task (Id : Integer; Lower_Fork, Higher_Fork : not null access Fork.Fork_Type; Meal_Limit : Integer) is
        entry Start;
    end Philosopher_Task;
end Philosopher;