"""
This file contain functions related to storing
all the events happing in the system/application.

For example logging in is an event. So, required 
information related to log in along with timestamp
will get stored in 'history' vertex collection/table 
of database.

"""

# standard library imports
# ------------------------
import datetime


# third party imports
# -------------------

from app.models.models import (
    graph,
    user,
    meetings,
    orgs,
    improve_us,
    contact_us,
    teams,
    event_history,
    user_meeting,
    user_org,
    user_team_edge,
    user_improve_us,
)

def time_stamp():
    """
    Returns the descriptive time to the calling function.
    """
    return str(datetime.datetime.now())


def initialise_event_log(event_type):
    """
    It will initialise data dict to be stored in history vertex
    of DB along with event type as one of it's attribute.
    """
    event_log_dict = {}
    event_log_dict['time stamp'] = time_stamp()
    event_log_dict['event_type'] = event_type
    return event_log_dict


def insert_event(event_data):
    """
    It will insert the'event_data' to the database.
    """
    event_data = event_history.insert({
        'EventData':event_data
    })
    return event_data


def get_all_data_about_event(event_body):
    """
    This function will fetch all data from the DB related to
    'event_body' parameter.
    """
    vert = graph._get_col_by_vertex(event_body['_id'])
    event_body = vert.__getitem__(event_body['_key'])
    return event_body


def event_processor(event_type,event_body):
    """
    This function processes all events generated in the system
    and store it in DB.
    """
    event_log_dict = initialise_event_log(event_type)
    event_log_dict['event_body'] = get_all_data_about_event(event_body)
    return insert_event(event_log_dict)
