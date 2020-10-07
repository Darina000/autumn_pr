//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
class FooA
{
    friend class K;
private:
    void Hello();
    void Hello2();
    void Hello3();
    int m_iData;

};

class K
{
private:
   static void Hello(FooA& obj)
   {
      obj.Hello();
   }
   static void Hello2(FooA& obj)
   {
      obj.Hello2();
   }
   friend class FooB;
};

class FooB
{
    void fun()
    {
        FooA objA;
        K::Hello(objA);  // right
        K::Hello2(objA); // right
       // objA.Hello3() // compile error
        //ojbA.m_iData = 0; // compile error
    }
};

class FooC
{
    void fun()
    {
        FooA objA;
       // objA.Hello();  // compile error
     //   objA.Hello2(); // compile error
       // objA.Hello3(); // compile error
      //  ojbA.m_iData = 0; // compile error
    }
};

int main(){
    return 0;
}
