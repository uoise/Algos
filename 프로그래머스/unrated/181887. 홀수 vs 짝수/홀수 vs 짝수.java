import java.util.stream.IntStream;

class Solution {
	public int solution(int[] num_list) {
		return Math.max(IntStream.range(0, num_list.length).filter(i -> i % 2 == 0).map(i -> num_list[i]).sum(),
			IntStream.range(0, num_list.length).filter(i -> i % 2 == 1).map(i -> num_list[i]).sum());

	}
}