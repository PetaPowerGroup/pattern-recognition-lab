#pragma once
class Baza;

class Trainer//za sada nam ne treba jer æemo preko datoteke trenirati svm - mozda jednog dana, ali ipak... YAGNI :)
{
public:
	Trainer(void);
	~Trainer(void);
	void /*struct svm_model*/ svm_train(Baza baza);
};
