import io, os
from typing import Union
import cProfile, pstats
from functools import wraps

def profile(output_file : str, sort_by='cumulative', lines_to_print: Union[int, float]=1.0, strip_dirs: bool=False, reverse_order: bool=False):
    """A time profiler decorator.
    
    Parameters
    ----------
        output_file: str or None. Default is None
            Path of the output file. If only name of the file is given, it's
            saved in the current directory.
            If it's None, the name of the decorated function is used.
        sort_by: str or SortKey enum or tuple/list of str/SortKey enum
            Sorting criteria for the Stats object.
            For a list of valid string and SortKey refer to:
            https://docs.python.org/3/library/profile.html#pstats.Stats.sort_stats
        lines_to_print: int or None
            Number of lines to print. Default (None) is for all the lines.
            This is useful in reducing the size of the printout, especially
            that sorting by 'cumulative', the time consuming operations
            are printed toward the top of the file.
        strip_dirs: bool
            Whether to remove the leading path info from file names.
            This is also useful in reducing the size of the printout
        reverse_order: bool
            Whether to reverse the info or not.
    Returns
    -------
        Profile of the decorated function
    """

    def inner(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            pr = cProfile.Profile()
            pr.enable()
            try:
                retval = func(*args, **kwargs)
            finally:
                pr.disable()
                s = io.StringIO()
                ps = pstats.Stats(pr, stream=s)
                
                if strip_dirs:
                    ps.strip_dirs()
                if isinstance(sort_by, (tuple, list)):
                    ps.sort_stats(*sort_by)
                else:
                    ps.sort_stats(sort_by)
                if reverse_order:
                    ps.reverse_order()
                ps.print_stats(lines_to_print)
                
                cur_path = os.path.dirname(__file__)
                _output_file = os.path.join(cur_path, f'{output_file}.log')
                with open(_output_file, 'a') as f:
                    f.write(s.getvalue())
                    f.close()

            return retval

        return wrapper

    return inner
