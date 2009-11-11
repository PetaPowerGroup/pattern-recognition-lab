#pragma once

class Trainer
{
public:
	Trainer(void);
	~Trainer(void);
	struct svm_model train();
};
