SELECT member.MEMBER_NAME, review.REVIEW_TEXT, date_format(review.REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
FROM REST_REVIEW as review INNER JOIN MEMBER_PROFILE as member ON review.MEMBER_ID=member.MEMBER_ID
WHERE review.MEMBER_ID in ( SELECT MEMBER_ID
                            FROM REST_REVIEW
                            GROUP BY MEMBER_ID
                            HAVING COUNT(REVIEW_ID) = ( SELECT MAX(count) as MAX
                                                        FROM (  SELECT MEMBER_ID, COUNT(REVIEW_ID) as count
                                                                FROM REST_REVIEW
                                                                GROUP BY MEMBER_ID ) as a ))
ORDER BY 3, 2