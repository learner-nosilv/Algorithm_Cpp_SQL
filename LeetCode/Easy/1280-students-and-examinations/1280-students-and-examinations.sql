-- SELECT stdSub.student_id, stdSub.student_name, stdSub.subject_name, count(exm.student_id) as attended_exams
-- FROM    ( SELECT *
--           FROM Students as std CROSS JOIN Subjects as sub ) as stdSub
--         LEFT JOIN Examinations as exm
--         ON stdSub.student_id = exm.student_id AND stdSub.subject_name = exm.subject_name
-- GROUP BY 1, 3
-- ORDER BY 1, 3

SELECT stdSub.student_id, stdSub.student_name, stdSub.subject_name, count(exm.student_id) as attended_exams
FROM ( SELECT *
       FROM Students as std CROSS JOIN Subjects as sub ) as stdSub
    LEFT JOIN Examinations as exm
    ON stdSub.student_id = exm.student_id AND stdSub.subject_name = exm.subject_name
GROUP BY 1, 3
ORDER BY 1, 3