## **To Do**

### homework1
   - overload operator << and  >> for input and output 
### homework2
   - change copying part so that it copies with holes
   - count physical size (will be easy after copying with holes)
### homework3
   - The child process, while exucuting should redirect its std streams this way
- - The stdout of child should be redirected to path /opt/silentshell/{PID}/out.std
- - The stderr of child should be redirected to path /opt/silentshell/{PID}/err.std
-- The stdin of child should be reading input from path  /opt/silentshell/{PID}/in.std
