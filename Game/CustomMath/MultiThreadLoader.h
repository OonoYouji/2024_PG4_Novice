#pragma once

/// std
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>


/// @brief タスクの型
using Task = std::function<void()>;

/// @brief マルチスレッドでの読み込みを行うクラス
class MultiThreadLoader final {
public:

	MultiThreadLoader();
	~MultiThreadLoader();

	void Initialize();
	void Finalize();

	/// @brief タスクを追加する
	/// @param _task 追加するタスク
	void AddTask(const Task& _task);

private:

	const size_t             kThreadNum_  = 4;
	const size_t             kMaxTaskNum_ = 100;

	std::vector<std::thread> threads_;
	std::mutex               mutex_;
	std::condition_variable  condition_;

	std::queue<Task>         tasks_;

	bool                     exit_        = false;

};