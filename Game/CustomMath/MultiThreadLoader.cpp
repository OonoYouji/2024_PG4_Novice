#include "MultiThreadLoader.h"

/// engine
#include <Novice.h>


MultiThreadLoader::MultiThreadLoader() {}
MultiThreadLoader::~MultiThreadLoader() {}

void MultiThreadLoader::Initialize() {

	/// スレッドを生成
	for(size_t i = 0; i < kThreadNum_; ++i) {
		threads_.emplace_back([this]() {

			/// 終了フラグが立つまでループ
			while(!exit_) {

				Task task;
				{
					std::unique_lock<std::mutex> lock(mutex_);
					condition_.wait(lock, [this]() { return !tasks_.empty() || exit_; });
				
					/// exit_がtrueになったらループを抜ける
					if(exit_) { break; }

					task = tasks_.front();
					tasks_.pop();
				}
				task();

			}
		});
	}

}

void MultiThreadLoader::Finalize() {
	exit_ = true;

	condition_.notify_all();
	for(auto& thread : threads_) {
		thread.join();
	}
}


void MultiThreadLoader::AddTask(const Task& _task) {

	/// タスクの数がkMaxTaskNumを超えていたら追加しない
	if(tasks_.size() >= kMaxTaskNum_) {
		Novice::ConsolePrintf("タスクの数が最大数を超えています");
		return;
	}

	tasks_.push(_task);

	if(!tasks_.empty()) {
		condition_.notify_all();
	}
}

