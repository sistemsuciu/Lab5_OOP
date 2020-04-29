// This header contains the definition of the class "Movie".

#pragma once
#include <string>

class Movie
{
	int ID;
	std::string Title;
	std::string Genre;
	int ApparitionYear;
	int NumberOfLikes;
	std::string Trailer;

public:
	Movie();
	Movie(int& ID);
	Movie(int& ID, std::string& Title, std::string& Genre, int& ApparitionYear, int& NumberOfLikes, std::string& Trailer);
	~Movie();

	int get_id();
	std::string get_title();
	std::string get_genre();
	int get_apparition_year();
	int get_number_of_likes();
	std::string get_trailer();

	void set_id(int id);
	void set_title(std::string Title);
	void set_genre(std::string Genre);
	void set_apparition_year(int Year);
	void set_number_of_likes(int Number);
	void set_trailer(std::string Trailer);

	void Play();
};

