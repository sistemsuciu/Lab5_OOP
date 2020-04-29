// This header contains the definition of the class "Controller".
#pragma once
#include "Repository.h"
#include "Watchlist.h"

class Controller
{
private:
	Repository movies_list;
	Repository watchlist;
public:
	Controller();
	Controller(const Repository& r) : movies_list(r) {}
	~Controller();

	Repository get_repository();
	Repository get_watchlist_repo();
	void add_movie_to_repository(int& ID, std::string& Title, std::string& Genre, int& ApparitionYear, int& NumberOfLikes, std::string& Trailer);
	void add_movie_to_watchlist(int& ID, std::string& Title, std::string& Genre, int& ApparitionYear, int& NumberOfLikes, std::string& Trailer);
	void delete_movie_from_repository(int& ID);
	void delete_movie_from_watchlist(int& ID);
	void update_title(int& ID, std::string& Title);
	void update_genre(int& ID, std::string& Genre);
	void update_number_of_likes(int& ID, int& Number);
	void update_trailer(int& ID, std::string& Trailer);
	DynamicVector search_by_genre(std::string& Genre);
	DynamicVector get_all_movies();
	bool find_movie(int& ID);
	bool number_validation(int Number);
	bool year_validation(int Year);
};

