# json-c-wrapper
This is a functional wrapper written over the json-c library ( Which is still not functional. Basic functionalities are being added..)

Now, the JSON is becoming a common format for interprocess as well as inter service communication in web and I have dealt with JSON a lot. Languages like Java, JS and Python doesn't throw some obstacles while dealing with JSON but C....well C is C.

Now there are scenarios wherein JSON would come into picture while using C. That is whenever you are deaing with REST APIs or maybe you are performing some interprocess communication with an application which takes value only in JSON, or maybe you are just trying to work with Document based DBs.

So, after much thought and endless time spent on bypassing the JSON-C library when dealing with REST APIs ( come on you would have atleast once in your life would have used the string manipulation to work with JSON in C), I have decided to create some sort of wrapper upon the already existing library.

Now, for the user out there, this is not a JSON library. I'm building upon a already existing library to just add some cosmetics here and there, which can come in handy if you don't want to go deep into the JSON-C library.

## Dependency
One would need to clone from the repository of [json-c/json-c](https://github.com/json-c/json-c), build it, because the wrapper is writtern over the said library.

## API List

The idea was to create set of wrapper functions for the already existing json-c library and hence there are various functions. This section deals with the description of the functions and how better to use it.

Now, The functions can be divided into a subsets which would be easier to see how they are useful to a user who might be dealing with JSON in everyday life.

### Creating new JSON Object with some initital element(s)

This is when you want to create a new JSON object which will be one of the base types. 
One needn't initialize the json_object when passing it to the function as an arguemnt, i.e. ``` json_object* jobj = json_object_new()``` operation would be taken care by the functions itself, hence the developer can use the json object just as any regualr variable (with strings attached though...)

The function names, yes. I agree not the best names, I would actually suggest people to get some sane names. But for now, I'm sticking to this.

The return value is such that 0 is success and negative values should ring a alarm bell.

|S No.| Function Declaration|  
|:---:|------------------------------------------------------------------------|
|1.|int new_jobj_bool_val(json_object \*jobj, const char \*key, int value )        |  
|2.|int new_jobj_int_val(json_object \*jobj, const char \*key, int value)            |
|3.|int new_jobj_double_val(json_object \*jobj, const char \*key, double value)      |
|4.|int new_jobj_string_val(json_object \*jobj, const char \*key, const char \*value)|
|5.|int new_jobj_jarr_val(json_object \*jobj, const char \*key, json_object \*jarr)|
|6.|int new_jobj_jobj_val(json_object \*jobj1, const char \*key, json_object \*jobj2)|
|7.|int new_jobj_bool_arr(json_object \*jobj, const char \*\*key_arr, int \*value, int int_arr_len)|
|8.|int new_jobj_int_arr(json_object \*jobj, const char \*\*key_arr, int \*int_arr, int int_arr_len)|
|9.|int new_jobj_double_arr(json_object \*jobj, const char \*\*key_arr, double \*double_arr, int double_arr_len)|
|10.|int new_jobj_string_arr(json_object \*jobj, const char \*\*key_arr, char \*\*string_arr, int string_arr_len)|
|11.|int new_jobj_jobj_arr(json_object \*jobj, const char \*\*key_arr, json_object \*\*jobj_arr, int jobj_arr_len)|
|12.|int new_jobj_jarr_arr(json_object \*jobj, const char \*\*key_arr, json_object \*\*jarr_arr, int jarr_arr_len)|


### Adding new element(s) into an existing JSON Object.

I think the topic is enough to understand the operation being undertaken here. But still its safe to mention that the JSON objects aren't initialized inside the function as it is assumed that one is updating an existing JSON object. So jumping directly into the function declarations.

|S No.| Function Declaration|  
|:---:|------------------------------------------------------------------------|
|1.|int push_jobj_bool_val(json_object \*jobj, const char \*key, int value )        |  
|2.|int push_jobj_int_val(json_object \*jobj, const char \*key, int value)            |
|3.|int push_jobj_double_val(json_object \*jobj, const char \*key, double value)      |
|4.|int push_jobj_string_val(json_object \*jobj, const char \*key, const char \*value)|
|5.|int push_jobj_jarr_val(json_object \*jobj, const char \*key, json_object \*jarr)|
|6.|int push_jobj_jobj_val(json_object \*jobj1, const char \*key, json_object \*jobj2)|
|7.|int push_jobj_bool_arr(json_object \*jobj, const char \*\*key_arr, int \*value, int int_arr_len)|
|8.|int push_jobj_int_arr(json_object \*jobj, const char \*\*key_arr, int \*int_arr, int int_arr_len)|
|9.|int push_jobj_double_arr(json_object \*jobj, const char \*\*key_arr, double \*double_arr, int double_arr_len)|
|10.|int push_jobj_string_arr(json_object \*jobj, const char \*\*key_arr, char \*\*string_arr, int string_arr_len)|
|11.|int push_jobj_jobj_arr(json_object \*jobj, const char \*\*key_arr, json_object \*\*jobj_arr, int jobj_arr_len)|
|12.|int push_jobj_jarr_arr(json_object \*jobj, const char \*\*key_arr, json_object \*\*jarr_arr, int jarr_arr_len)|


### Creating new JSON Array with some initital element(s)

Now, comes the part wherein we create the JSON array with one single element, and yes it is specific to the type.
Again, one doesn't need to initialize the json_object being passed to the function as it will be instantiated inside the function itself. The return values behave in the same manner as before. 0 being an indication of successful operation.

In addition to adding single elements like a string or integer or double value, one can also add multiple values which can be passed using an array.

|S No. | Function Declaration|  
|:--:|------------------------------------------------------------------------|
| 1. | int new_jarr_bool_val(json_object \*jarr, int value)        |  
| 2. | int new_jarr_int_val(json_object \*jarr, int int_val)            |
| 3. | int new_jarr_double_val(json_object \*jarr, double double_val)      |
| 4. | int new_jarr_string_val(json_object \*jarr, const char \*string_val))|
| 5. | int new_jarr_jarr_val(json_object \*jarr1, json_object \*jarr2)        |
| 6. | int new_jarr_jobj_val(json_object \*jarr, json_object \*jobj) |
| 7. | int new_jarr_bool_arr(json_object \*jarr, int \*bool_arr, int int_bool_len)|
| 8. | int new_jarr_int_arr(json_object \*jarr, int \*int_arr, int int_arr_len) |
| 9. | int new_jarr_double_arr(json_object \*jarr, double \*double_arr, int double_arr_len) |
| 10.| int new_jarr_string_arr(json_object \*jarr, char \*\*string_arr, int string_arr_len) |
| 11.|int new_jarr_jobj_arr(json_object \*jarr, json_object \*\*jobj_arr, int jobj_arr_len)|
|12.|int new_jarr_jarr_arr(json_object \*jarr, json_object \*\*jarr_arr, int jarr_arr_len)|

