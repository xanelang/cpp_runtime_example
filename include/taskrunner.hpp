/*
 * taskrunner.hpp
 *
 *  Created on: May 11, 2018
 *      Author: Issac
 */

#ifndef INCLUDE_TASKRUNNER_HPP_
#define INCLUDE_TASKRUNNER_HPP_

#include "core.hpp"
#include <iostream>

using namespace std;

template<typename TaskType>
struct TaskRunner: Object {
	TaskType task;

	TaskRunner() {
	}

	void execute() {
		cout << "Starting task ..." << endl;
		task.run();
		cout << "Done running task." << endl;
	}

	static TaskRunner init(TaskType task) {
		TaskRunner<TaskType> self;
		self.task = task;
		return self;
	}
};

struct MyTask: Object {
	Int id;
	MyTask() {
	}
	void run() {
		print(
				String::init_fromLiteral("Running task ")->operator +(
						id.toString())->operator +(
						String::init_fromLiteral(" ...")));
	}

	static MyTask init(Int id) {
		MyTask self;
		self.id = id;
		return self;
	}
};

#endif /* INCLUDE_TASKRUNNER_HPP_ */
