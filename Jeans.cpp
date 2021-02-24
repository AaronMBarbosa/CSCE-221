/**
 * In this file, implement the methods from Jeans.h. The implementation is identical to Stress_ball
 * This file needs to be uploaded to Mimir
 */ 
#include "Jeans.h"

Jeans::Jeans() {

	color = static_cast<Jeans_colors>(rand()%4);
	size = static_cast<Jeans_sizes>(rand()%2);

}

Jeans::Jeans(Jeans_colors c, Jeans_sizes s) {
	
	color = c;
	size = s;
	
}

Jeans_colors Jeans::get_color() const {
	return color;
}

Jeans_sizes Jeans::get_size() const {
	return size;
}

bool Jeans::operator==(const Jeans& sb) {
	
	if( color == sb.color && size == sb.size) {
		return true;
	}
	
	return false;
}

ostream &operator<<(ostream &o, const Jeans& sb) {
	
	switch (sb.get_color()) {
		
		case Jeans_colors::white:
			o << "(white";
			break;
		case Jeans_colors::black:
			o << "(black";
			break;
		case Jeans_colors::blue:
			o << "(blue";
			break;
		case Jeans_colors::grey:
			o << "(grey";
			break;
	}
	switch (sb.get_size()) {
		
		case Jeans_sizes::small:
			o << ", small)";
			break;
		case Jeans_sizes::medium:
			o << ", medium)";
			break;	
		case Jeans_sizes::large:
			o << ", large)";
			break;
		case Jeans_sizes::xlarge:
			o << ", xlarge)";
			break;
		
	}
	
	return o;
}