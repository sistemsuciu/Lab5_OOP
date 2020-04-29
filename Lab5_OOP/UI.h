#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	void AddMovie();
	void DeleteMovie();
	void DeleteMovieFromWatchlist();
	void UpdateTitle();
	void UpdateGenre();
	void UpdateNumberOfLikes();
	void UpdateTrailer();
	void ShowAllMovies();
	void ShowMoviesByGenre();
	void ShowWatchlist();

public:
	UI(Controller& c) : ctrl(c) {};
	UI();
	~UI();
	void run();
};

