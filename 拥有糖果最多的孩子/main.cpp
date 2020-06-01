lass Solution {
	public:
		    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
			            int max = candies[0];
				            for(auto i : candies){
						                if(i > max){
									                max = i;
											            }
								        }

					            vector<bool> ret;

						            for(auto i : candies){
								                if((i + extraCandies) >= max){
											                ret.push_back(true);
													            }else{
															                    ret.push_back(false);
																	                }
										        }

							            return ret;
								        }
};
