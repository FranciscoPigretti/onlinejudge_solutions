#include <iostream> // cin, cout
#include <map>

using namespace std;


int main() {
    
    int test_cases;
    scanf("%d", &test_cases);

    map<int,int> my_map;

    int snowflake;


    while(test_cases--) {        
        int number_of_snowflakes;
        scanf("%d", &number_of_snowflakes);

        my_map.clear();
        int count = 0;
        int max = 0;

        int inicio = 0;    

        for (int i = 0; i < number_of_snowflakes; i++) {          
            scanf("%d", &snowflake);

            if (my_map.count(snowflake)>0 && my_map[snowflake] >= inicio) {
                if (count > max) max = count;
                count =  i - my_map[snowflake];
                inicio = my_map[snowflake] + 1;                
            } else {
                count++;
            }

            my_map[snowflake] = i;
        }        

        if (count > max) max = count;


        cout << max << endl;

    }

}