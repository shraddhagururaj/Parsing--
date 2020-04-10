#include<stdio.h>
#include<json-c/json.h>                                                                  //library to parse json 

int main(int argc, char **argv) 
{
	FILE *fp;
	char buff[1024];
	struct json_object *parsed_json;                                                 //structure to hold json
	struct json_object *name;                                                        //structure to hold fields parsed
	struct json_object *age;
	struct json_object *friends_list;
	struct json_object *friend;                                                     // to hold each item of friends array
	size_t num_friends;
	size_t i;	

	fp = fopen("test.json","r");
	fread(buff, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buff);

	json_object_object_get_ex(parsed_json, "name", &name);                        //to get value of a key in JSON object
	json_object_object_get_ex(parsed_json, "age", &age);
	json_object_object_get_ex(parsed_json, "friends", &friends_list);

	printf("Name: %s\n", json_object_get_string(name));
	printf("Age: %d\n", json_object_get_int(age));
	num_friends = json_object_array_length(friends_list);
	printf("%s has %lu friends\n",json_object_get_string(name),num_friends);

	for(i=0;i<num_friends;i++)
	{
		friend = json_object_array_get_idx(friends_list, i);
		printf("%lu. %s\n",i+1,json_object_get_string(friend));
	}	
}
