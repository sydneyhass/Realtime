# Assignment 1
## Create state machine diagram
> Example scenario contains tokenized string
1. Left Scan

> Bogus inputs will not be provided - data validation should be done

### Not Optimized SMD
Start State → (ls) → Left Scan / Input State → \(\<Int\>\) →

> ls is inbound → person needs to do left-open (lo)
> 
> Finite state machine is 23 states → can be optimized down to 7(?) states - must handle inbound/outbound states
> 
> First optimization is that **rs, ls, ws** all need an int argument
> 
> Controller connects to display and inputs
> 
> Second optimization: remove direction - add another field to person object for inbound/outbound (enum) → person.direction
> - left/right states can be collapsed into state

## PDL: des-inputs
> des-inputs is the client of des-controller (server)

### Phase 1
Process cli-args → get PID of controller

- `int coid = ConnectAttach()` to controller

### Phase 2
```C
while(1) {
    // Prompt user for input → printf("Enter")
    // GET user input → scanf()
    // IF input == "ls" || "rs" 
    // THEN prompt for person's ID
    // GET person's ID → scanf() - Int
    // IF input == "ws"
    // THEN prompt for weight
    // GET person's weight → scanf() - Int
    // SEND person struct to controller: MsgSend(coid, &person, sizeof(person), NULL, 0)
    // IF input == "exit"
    // THEN break out of loop
}
```

> Terminate with dez event type command exit

### Phase 3
- Call `ChannelDetach()`
- `exit(EXIT_SUCCESS)`

## PDL: des-controller
> Dual mode controller → server (to inputs) & client (to display)

### Phase 1
- Process cli-args → get PID of display
- Call `int chid = ChannelCreate(0);` // for inputs
- Call `int coid = ConnectAttach();` // attach to display
  - Needs nid, chid, coid

> Assume defensive programming - perror out of all functions 

### Phase 2
```C
while(1) {
    // Receive person object from inputs → MsgReceive(chid, &person, sizeof(person), NULL)
    // TODO: Reference CST8152 Notes - State Machine Implementation
    // Process state machine based on current state & person state
    // Send display struct to display server
    MsgSend(coid, &display, sizeof(display), NULL, 0) → coid from phase 1
    // Reply to inputs: EOK
    MsgReply(rcvid, EOK, NULL, 0)
    // IF message from input == "exit"
    // THEN send an exit message to display
    // AND break out of loop
}
```

### Phase 3
- `Detach` from Display's channel
- `DestoryChannel` to inputs
- `exit(EXIT_SUCCESS)`

## PDL: des-display
> Server to the controller

### Phase 1
- `int chid = ChannelCreate(0)` → Controller channel

### Phase 2
```C
while(1) {
    // Receive display object from controller
    MsgReceive(chid, &display, sizeof(display), NULL);
    // Reply to controller
    MsgReply(rcvid, EOK, NULL, 0);
    // IF message from controller is SCAN.STATE → #define (ls or rs)
    // THEN display person has been scanned and there id is <int>
    // IF message from controller is WEOGHED
    // THEN display person has been weighed and their weight is <int>
    // ELSE display the message
    // IF message from controller == "exit"
    // THEN break out of loop
}
```

### Phase 3
### Phase 3
- `DestroyChannel` to controller
- `exit(EXIT_SUCCESS)`