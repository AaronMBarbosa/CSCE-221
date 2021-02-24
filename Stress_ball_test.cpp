/**
 *  Fill the (...) below in such a way that Collection objects are created.
 *  Use aliases CollectionSB for Collection of Stress_balls.
 *  Reuse Operator>> (from PA1-p2) for Collection of Stress_balls.
 *  This file needs to be uploaded to Mimir.
 * 
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "Stress_ball.h"
#include "Collection.h"

using CollectionSB = Collection < Stress_ball , Stress_ball_colors , Stress_ball_sizes >;

istream& operator>>(istream& is, CollectionSB& c){
 
  string tempclr;
  string tempsze;
  Stress_ball_colors clr;
  Stress_ball_sizes sze;
  while (is >> tempclr >> tempsze) {
	  if(tempclr == "red") {
		clr = Stress_ball_colors::red;
	  }
	  if(tempclr == "blue") {
		clr = Stress_ball_colors::blue;
	  }
	  if(tempclr == "yellow") {
		clr = Stress_ball_colors::yellow;
	  }
	  if(tempclr == "green") {
		clr = Stress_ball_colors::green;
	  }
	  
	  if( tempsze == "small") {
		sze = Stress_ball_sizes::small;
	  }
	  if( tempsze == "medium") {
		sze = Stress_ball_sizes::medium;
	  }
	  if( tempsze == "large") {
		sze = Stress_ball_sizes::large;
	  }
	  
	  Stress_ball tempsb(clr, sze);
	  c.insert_item(tempsb);
	  
	  
  }
	  
	
 
  return is;
}
void test_stress_balls(){
        Stress_ball stress_ball_1 = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large);
        Stress_ball stress_ball_2 = Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::large);
        Stress_ball stress_ball_3 = Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small);
        Stress_ball stress_ball_4 = Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium);
        CollectionSB collection_1;
        CollectionSB collection_2(3);
        CollectionSB collection_3(5);
        CollectionSB collection_file(1);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(stress_ball_4);
        collection_1.insert_item(stress_ball_1);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        CollectionSB collection_4 = collection_1;
        CollectionSB collection_5(move(collection_4));
        collection_1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        collection_2.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        collection_2.remove_this_item(stress_ball_2);        
        collection_2.print_items();
        ifstream ifs("stress_ball1.data");
        ifs >> collection_file;
        collection_file.insert_item(stress_ball_3);
        collection_file.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_3);
        collection_2.insert_item(stress_ball_2);
        collection_2.insert_item(stress_ball_1);
        
        collection_file.print_items();
        collection_3 = make_union(collection_file,collection_2);
        cout<<collection_3;
}

