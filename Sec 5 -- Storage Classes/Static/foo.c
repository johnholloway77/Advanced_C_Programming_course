extern int fun();

void callFun()
{

    fun();
}

static void staticCallFun() //inaccessable from outside file
{
    fun();
}
