"""
This file contains all the schemas used all over the app

"""

# security : forgot passwword schemas

import datetime,re
from datetime import date
from fastapi import Form
from typing import Optional, List, Dict
from pydantic import BaseModel, EmailStr
from starlette.requests import Request


# Schema dependency


class EmailSchema:
    """
    Pydantic Schema for email account recovery.

    Attributes
    ----------
    email : str
        The email where the recovery mail would be sent.
    """

    def __init__(self, email: str = Form(...)):
        """
        Parameters
        ----------
        email : HTML Form
            Would initialize the email from the submitted html form.
        """

        self.email = email


class NewPassword:
    """
    Pydantic Schema for account password.

    Attributes
    ----------
    password : str
        The new password that user will enter after forgot email verification.
    """

    def __init__(self, password: str = Form(...)):
        """
        Parameters
        ----------
        password : HTML Form
            Would initialize the password from the submitted html form.
        """

        self.password = password


class SentPasscode:
    """
    Pydantic Schema for email account recovery.

    Attributes
    ----------
    passcode : str
        The passcode sent to the user on their mail.
    """

    def __init__(self, passcode: str = Form(...)):
        """
        Parameters
        ----------
        passcode : HTML Form
            Would initialize the passcode from the submitted html form.
        """

        self.passcode = passcode


class user_item:
    """
    pydantic schema for new user sign-up
    """
    def __init__(self,
                 username: str = Form(...),
                 email: EmailStr = Form(...),
                 password: str = Form(...),
                 company: str = Form(...),
                 position: str = Form(...),
                 location: str = Form(...)
                 ):

        self.username = username
        self.email = email
        self.password = password
        self.company = company
        self.position = position
        self.location = location


class meeting_summary(BaseModel):
    '''
    Pydantic Schema for summary of users after meeting is completed.
    '''
    user: str
    summary: List[str]


class meeting_item(BaseModel):
    '''
    pydantic schema for meeting history.
    '''
    subject: str
    location: str
    link: str
    key: str
    created_date: str
    created_time: str
    date: str
    starttime: str
    duration: str
    invitees: list
    attended_y: List[str]
    attended_n: List[str]
    agenda: str
    # summary:List[meeting_summary]


class login_user_schema(BaseModel):
    """
    Pydantic schema for user login
    Currently the username is same as email
    """
    username: str
    name: Optional[str] = None
    email: Optional[str] = None
    disabled: Optional[bool] = None


class Token(BaseModel):
    """
    JWT token schema
    """    
    access_token: str
    token_type: str


class TokenData(BaseModel):
    """
    schema to check for payload
    """
    username: Optional[str] = None


class UserInDB(login_user_schema):
    """
    schema to append hashed_password to 
    login_user_schema for security.
    """
    hashed_password: str
    

class user_meeting_edge_item(BaseModel):
    """
    pydantic schema for user to meeting edge.
    """
    To:str
    From:str
    Date:str
    Host:str


class teams_item(BaseModel):
    """
    pydantic schema for newly formed team.
    """
    Team_name:str
    Created_at:str
    Disabled_yn:bool
    Members:Dict

class user_team_edge(BaseModel):
    """
    pydantic schema for user - team edge.
    """
    From:str
    To:str

"""
for posting active hours into active_hours vertex
"""
class ActiveHours(BaseModel):
    username: str
    start_time: str
    end_time: str

"""
for posting busy hours into busy_hours vertex
"""
class BusyHours(BaseModel):
    username: str
    meeting_date : str
    start_time: str
    end_time: str


class CommonSlots(BaseModel):
    users: List


class file_schema(BaseModel):
    '''
    Pydantic Schema for insertion of new file into file system.
    '''
    filename : str
    file_type : str
    file_relation : str
    file_path : str



class project_item:
    """
    pydantic schema for new project form
    """
    def __init__(self,
                 FieldType: str = Form(...),
                 ProjectName: str = Form(...),
                 ExpectedEndDate: date = Form(...),
                 ProjectDescription: str = Form(...),
                 AdminName: str = Form(...),
                 StartedOn: date = Form(...),
                 ActiveYN: str = Form(...)
                 ):

        match = re.search(r'([\d]+)-([\d]+)-([\d]+)',str(ExpectedEndDate))
        E_year = match.group(1)
        E_month = match.group(2)
        E_date = match.group(3)

        match = re.search(r'([\d]+)-([\d]+)-([\d]+)',str(StartedOn))
        S_year = match.group(1)
        S_month = match.group(2)
        S_date = match.group(3)

        if E_year < S_year:
            raise ValueError("Invalid Expected End Date with respect to Started On.")
            
        elif E_year == S_year and E_month < S_month:
            raise ValueError("Invalid Expected End Date with respect to Started On.")
    
        elif  E_year == S_year and E_month == S_month and E_date < S_date:
            raise ValueError("Invalid Expected End Date with respect to Started On.")


        self.FieldType = FieldType
        self.ProjectName = ProjectName
        self.ExpectedEndDate = ExpectedEndDate
        self.ProjectDescription = ProjectDescription
        self.AdminName = AdminName
        self.StartedOn = StartedOn
        self.ActiveYN = ActiveYN
