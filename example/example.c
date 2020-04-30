/*
	Author: schaffung
	Date: 01/05/2020
	
	The example demonstrated here is inline with the feautures
	available in the libjsoncwrapper.
	
	So, currently, the following will be done,
	Stage 1. Object having values of type int, string, boolean, array and double are created.
	Stage 2. These objects are added as a part of a main object.
	Stage 3. The final object is converted into string.

*/

#include <stdio.h>
#include "libjsoncwrapper.h"


int main()
{
	// Stage 1.
	json_object *int_object = NULL, *bool_object = NULL, *string_object = NULL, *arr_object = NULL, *double_object = NULL;
	
	if( create_json_int(int_object, "Key1", 1) == -1 )
	{
		printf("Error in creation of a JSON object with integer value.\n");
	}
	
	if( create_json_string(string_object, "Key2", "Value_string") == -1)
	{
		printf("Error in creation of a JSON object with string value.\n");
	}
	
	if( create_json_double(double_object, "Key3", 1.0) == -1)
	{
		printf("Error in creation of a JSON object with double value.]n");
	}
	
}