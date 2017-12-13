class BadIndex
{
   public:
     BadIndex (int i){index = i;}
     int GetIndex(){return index;}
     
   private:
     int index;
};

template <class T>
class BadValue
{
   public:
     BadValue(T v){value = v;}
     T GetValue(){return value;}
   private:
     T value;
};

class Full{};


template <class T>
class Object
{
   public:
     Object(int s=10)      //constructor
     { 
        size = s;
        current = 0;
        data = new T[size];
     }
     
     Object(const Object& other) //copy constructor
     {
       size = other.size;
       current = other.current;
       data = new T[size];
       for(int i = 0; i < current; i++)
         data[i] = other.data[i];
     }
     
     ~Object(){ delete [] data;}  //destructor
     
     void Add(T e) throw(Full, BadValue<T>)    // Add member function
     {
       if(size == current) throw Full();
       if(e < 0) throw BadValue<T>(e);
       data[current] = e;
       current++;
     }
     
     T& operator [] (int i) throw(BadIndex)
     {
        if(i< 0 || i >= current)
          throw BadIndex(i);
        return data[i];
     }
   
   private:
     int size;
     int current;
     T   *data;
};