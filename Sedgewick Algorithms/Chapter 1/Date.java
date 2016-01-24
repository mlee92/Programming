
class Date{
	
	private static final int[] DAYS = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	private int month;
	private int day;
	private int year; 
	
	public Date(int m, int d, int y){
		month = m;
		day = d;
		year = y;
	}
	
	public int getMonth(){ return month; }
	public int getDay(){ return day; }
	public int getYear(){ return year; } 
	
	public boolean isValid(int m, int d, int y){
		return (0 < m && m <= 12) && (0 < d && d <= DAYS[month]);
	}
	
	private static final String[] WEEKDAYS = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; 
	private static final int[] MONTH = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}; 
	private static final int[] CENTURY = {6, 4, 2, 0}; 
	
	public String getDayOfWeek(){
		int m = MONTH[month - 1];
		int yr = year % 100; 
		int yr_val = yr/4; 
		int c = (year / 100);
		int c_val = CENTURY[c % 4];
		int sum = (c_val + m + yr_val + yr) % 7; 
		return WEEKDAYS[sum];
	}
	
	public Date next() {
        if (isValid(month, day + 1, year))    
			return new Date(month, day + 1, year);
        else if (isValid(month + 1, 1, year)) 
			return new Date(month + 1, 1, year);
        else                                  
			return new Date(1, 1, year + 1);
    }

}