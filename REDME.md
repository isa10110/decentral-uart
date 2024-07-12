# Idea: 
building a Bus system with out central Authorety to  build a activitiy based aktivation. 

# System: 
Our Bus contains n element R nodes. 

One Node can be activated limitless often.

Each  note Contane a inner Value 

A Note can  communicate only with  all direct naibours. 

## How to realize it in Hardware? 

use Serial (Rx Tx) on a microcontroller and conect them  according to  this theme: 

the __ visolize a micro  controller 

```

__      __      __      __      __      __      __      __      __      __      __      __      __      __      __      
Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Tx
Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Tx-->|--Rx--|<--Rx

```

one pair of Rx and Tx match a microcontroller. 

The diods in the according polarety : 
```
- --|<-- + 
```
limeits the sicnal travel that one lamp  only can sent and recive from  his Naighbours.

# How to build a scalable lighnis improvements according to this system? 

## Light bragnis dater follows Aktivation 
each Mictocontroller represents in the following diagramm  a note. 

horezontely notes verticly data iterations 

```

   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 
---+------------------------------------
 1 | 0   0   0   0   4   0   0   0   0  
 2 | 0   0   0   3   4   3   0   0   0 
 3 | 0   0   2   3   4   3   2   0   0  
 4 | 0   1   2   3   4   3   2   1   0  
 5 | 0   1   2   3   4   3   2   1   0

```

The Numbers represents the inner values if  5 gets activated and the signal get reduced by one on any communikation step. 

the Note who gets the new messagetake  the higest value of inner or recived one.  and than transmit a next reduced data block. 

if multible activations happens the following structure would be createt

```

   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
---+------------------------------------
 1 | 0   0   3   0   0   3   0   0   0
 2 | 0   2   3   2   2   3   2   0   0
 3 | 1   2   3   2   2   3   2   1   0
 4 | 1   2   3   2   2   3   2   1   0
 5 | 1   2   3   2   2   3   2   1   0

```

Ackitivation  3 , 6 with 3.

We see  that will work in any cases. 

we  allso  see if the injekted value is smaller the resulting pytamid is smaller 
therefore a taller number produce a taller fiald of values. 
Prove 
horezontely notes verticly data iterations

``` 

   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
---+------------------------------------
 1 | 0   0   0   0   3   0   0   0   0
 2 | 0   0   0   2   3   2   0   0   0
 3 | 0   0   1   2   3   2   1   0   0
 4 | 0   0   1   2   3   2   1   0   0
 5 | 0   0   1   2   3   2   1   0   0

```

therefore we can variate with  the injected value at time of activation the first node.

if a node get activated and the bus has infinit speed 

the thunnele will follow you and the size of the aktivation is build by value of the activaton threshhold.

we want to  apply it to lamps therefore it shuld turn off.

to  bind the  thunnel of light to the agylity of the wihicle we can  build the acseption 


inner_thrashold > activation  and inner_threshold < maximum_thunnle 

increase the activation by some value. 

in all other cases set activaton value to  to  min activaton.

```
 
   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
---+------------------------------------
 1 | 0   0   0   3   0   4   0   0   0
 2 | 0   0   2   3   3   4   3   0   0
 3 | 0   1   2   3   3   4   3   2   0
 4 | 0   1   2   3   3   4   3   2   1
 5 | 0   1   2   3   3   4   3   2   1
 
 ```
 
We started on not 4 with an activation value of 3 and on  6 with 4.

the explaination workes better if we can visolize time too.  

this creates the effect that if an activation  has take place in past the  the next activation would be taller and therefore the light thunnel increases in size. 

the lamps shuld allso turn  off . 
therefore we shuld add a time based decreasing function to  the nodes. 

## First Problem solved. 
The Bus Dont have to be synced on a clock. 

and the time based reduction don't have to be synced. 

No  unwanted adding inteference take palce .

The bus Dont have a limit for there paticepents. 

you  can build crossways too.  

# we shuld bring this code to live.
see the regarding ino  file. 