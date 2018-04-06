# BufferOverFlowWithAssembly

- This Project demonstrates how to take advantage of a vulnerable app by Buffer Overflow Attack. 
- The assembly code passed as a runtime argument to the Vulnerable app enables the attacker to smash the stack and open the terminal with the permission of the app.

## Assumptions

- Turned off *Address Space Layout Randomization* `echo 0 | sudo tee /proc/sys/kernel/randomize va space`
- Turned off *Stack Canaries* `gcc -z execstack -fno-stack-protector -o victim victim.c`
