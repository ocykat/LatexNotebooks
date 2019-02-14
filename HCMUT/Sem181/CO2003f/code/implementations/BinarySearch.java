public class BinarySearch {
    /**
     *  @param  a     array
     *  @param  start first index
     *  @param  end   last index, exclusive
     *  @param  key   search key
     *  @return the index of an element equals to key, or
     *  -1 if no such element exists
     *  Time complexity: O(log(n))
    **/
    int binarySearch(int[] a, int start, int end, int key) {
        end--;
        int mid = (start + end) / 2;
        while (start < end && a[mid] != key) {
            if (a[mid] < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return (a[mid] == key) ? (mid) : (-1);
    }

    /**
     *  @param  a     array
     *  @param  start first index
     *  @param  end   last index, exclusive
     *  @param  key   search key
     *  @return the index of the leftmost element that is
     *  less than or equals to key
     *  Time complexity: O(log(n))
    **/
    int lowerBound(int[] a, int start, int end, int key) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (a[mid] >= key) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }


    /**
     *  @param  a     array
     *  @param  start first index
     *  @param  end   last index, exclusive
     *  @param  key   search key
     *  @return the index of the leftmost element that is
     *  strictly less than key
     *  Time complexity: O(log(n))
    **/
    int upperBound(int[] a, int start, int end, int key) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (a[mid] <= key) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
}