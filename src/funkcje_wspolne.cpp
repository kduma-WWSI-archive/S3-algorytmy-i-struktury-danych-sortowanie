//
// Created by Krystian Duma on 13/12/2017.
//

#include "funkcje_wspolne.h"

std::string pad_right(const std::string &str, size_t s) {
	if ( str.size() < s )
		return str + std::string(s-str.size(), ' ');
	else
		return str;
}
