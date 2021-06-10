#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <array>
#include <sstream>
#include <map>

using namespace std;

struct Card
{
    char face;
    char suite;
} hand[13];

int main()
{
    const int num_cards_in_hand = 13;
    const int num_suites = 4;

    while (scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c\n", &(hand[0].face), &(hand[0].suite), &(hand[1].face), &(hand[1].suite), &(hand[2].face), &(hand[2].suite), &(hand[3].face), &(hand[3].suite), &(hand[4].face), &(hand[4].suite), &(hand[5].face), &(hand[5].suite), &(hand[6].face), &(hand[6].suite), &(hand[7].face), &(hand[7].suite), &(hand[8].face), &(hand[8].suite), &(hand[9].face), &(hand[9].suite), &(hand[10].face), &(hand[10].suite), &(hand[11].face), &(hand[11].suite), &(hand[12].face), &(hand[12].suite)) >= 0)
    {

        map<char, int, std::greater<int>> num_cards_of_suit; // no se si de pedo, pero ese es el orden lexicografico decreciente
        num_cards_of_suit.insert(pair<char, int>('S', 0));
        num_cards_of_suit.insert(pair<char, int>('H', 0));
        num_cards_of_suit.insert(pair<char, int>('D', 0));
        num_cards_of_suit.insert(pair<char, int>('C', 0));

        map<char, bool> stopped_suites;
        stopped_suites.insert(pair<char, bool>('S', false));
        stopped_suites.insert(pair<char, bool>('H', false));
        stopped_suites.insert(pair<char, bool>('D', false));
        stopped_suites.insert(pair<char, bool>('C', false));

        int points_rule_1 = 0;
        int points_rules_234 = 0;
        int points_rules_567 = 0;

        // Regla 1 y calcular num_cards_of_suit
        for (int i = 0; i < num_cards_in_hand; i++)
        {
            if (hand[i].face == 'A')
                points_rule_1 += 4;
            if (hand[i].face == 'K')
                points_rule_1 += 3;
            if (hand[i].face == 'Q')
                points_rule_1 += 2;
            if (hand[i].face == 'J')
                points_rule_1 += 1;

            num_cards_of_suit[hand[i].suite]++;
        }

        // Reglas 234 y stopped
        for (int i = 0; i < num_cards_in_hand; i++)
        {
            if (hand[i].face == 'A')
                stopped_suites[hand[i].suite] = true;
            if (hand[i].face == 'K')
            {
                if (num_cards_of_suit[hand[i].suite] == 1)
                    points_rules_234 -= 1;
                if (num_cards_of_suit[hand[i].suite] >= 2)
                    stopped_suites[hand[i].suite] = true;
            }
            if (hand[i].face == 'Q')
            {
                if (num_cards_of_suit[hand[i].suite] <= 2)
                    points_rules_234 -= 1;
                if (num_cards_of_suit[hand[i].suite] >= 3)
                    stopped_suites[hand[i].suite] = true;
            }
            if (hand[i].face == 'J')
                if (num_cards_of_suit[hand[i].suite] <= 3)
                    points_rules_234 -= 1;
        }

        // reglas 567 y mayor bid si fuera bid
        int max = 0;
        char suit_to_bid = 'x';
        for (auto it = num_cards_of_suit.begin(); it != num_cards_of_suit.end(); ++it)
        {
            if (it->second == 2)
                points_rules_567 += 1;
            if (it->second == 1)
                points_rules_567 += 2;
            if (it->second == 0)
                points_rules_567 += 2;
            if (it->second > max)
            {
                suit_to_bid = it->first;
                max = it->second;
            }
        }

        // all stopped
        bool all_stopped = true;
        for (auto it = stopped_suites.begin(); it != stopped_suites.end(); ++it)
            if (it->second == false)
                all_stopped = false;

        if (points_rule_1 + points_rules_234 + points_rules_567 < 14)
            cout << "PASS" << endl;
        else
        {
            if ((points_rule_1 + points_rules_234 >= 16) && all_stopped)
            {
                cout << "BID NO-TRUMP" << endl;
            }
            else
            {

                cout << "BID " << suit_to_bid << endl;
            }
        }
    }
}
/*

// 1er pasada, leer y calcular num_cards

// 2unda pasada, sumar/restar reglas 234 y ver no trump

// extra



array<int, 4> num_cards_of_suit = {0,0,0,0};    // S, H, D, C


array<bool, 4> stopped_suits = {false,false,false,false};       // S, H, D, C


array<int, 4> extra_points_567

{KS, QS, TH, 8H, 4H, AC, QC, TC, 5C, KD, QD, JD, 8D}

{2, 3, 4, 4}

3  2  -   -  - 4  2  -  -  3  2  1  -

stopped = {true, false, true, true}


regla1: iterar 
-> sumar por face
-> restar por reglas 2,3,4

regla2: 

regla2,3,4


mapa de suits to cant de cartas

stopped_suits[bool]

contar y ver Ver si va no trump



*/