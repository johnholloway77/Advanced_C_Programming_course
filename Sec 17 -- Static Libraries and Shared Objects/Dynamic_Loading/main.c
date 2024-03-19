#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    printf("Dynamic Loading (not linking!!)\n");

    void *handle = NULL;
    double (*cosine)(double) = NULL;
    char *error = NULL;

    handle = dlopen("/usr/lib/libm.so", RTLD_LAZY);

    if(!handle){
        fputs (dlerror(), stderr);
        exit(1);
    }

    dlerror();

    cosine = dlsym(handle, "cos"); //creates a function pointer to cosine function

    if ((error = dlerror()) != NULL){
        fputs(error, stderr);
        exit(1);
    }
    printf("%f\n", (*cosine)(2.0));

    dlclose(handle);

    return 0;
}
