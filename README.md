# memory-management


|     Block address (Index)    |     Block size    |
|------------------------------|-------------------|
|     0                        |     2             |
|     1                        |     2             |
|     2                        |     4             |
|     3                        |     4             |
|     4                        |     16            |
|     5                        |     16            |
|     6                        |     32            |
|     7                        |     32            |
|     8                        |     64            |
|     9                        |     128           |

## API

`int allocate(process& process)` - 
finds place where to store process and returns its address

`void free(process& process)` - free the allocated space

`process getProcess(const string name)` - get the process by name

## BUILD AND RUN

```
git clone git@github.com:michaelkotor/memory-managment.git
cd mememory-managment
mkdir build
cmake ..
make
```

