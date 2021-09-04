Users@users : ~/Desktop/orderFlow/cpp: make  \\produce two exec file : waiter, kitchen
 In terminal1 : waiter
```bash
$ ./waiter
Waiter : waiter1 received Order 
Received order from customer1
Dish : A餐

Waiter : waiter1 received Order 
Received order from customer2
Dish : B餐

Deliver A餐 to  customer1

Waiter : waiter1 received Order 
Received order from customer3
Dish : C餐

Deliver B餐 to  customer2

Deliver C餐 to  customer3

```

In terminal2 : kitchen
```bash

initializing data reader..
Received order : A餐, staring cooking ...
Order : A餐 is finished. 
Ask waiter1 to deliver the dish
Received order : B餐, staring cooking ...
Order : B餐 is finished. 
Ask waiter1 to deliver the dish
Received order : C餐, staring cooking ...
Order : C餐 is finished. 
Ask waiter1 to deliver the dish
```
